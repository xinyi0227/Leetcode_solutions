int minimumTeachings(int totalLanguages, int **userLanguages, int userLanguagesSize, int *userLanguagesColSize, int **friendships, int friendshipsSize, int *friendshipsColSize)
{
    bool *usersToTeach = (bool *)calloc(userLanguagesSize, sizeof(bool));

    for (int i = 0; i < friendshipsSize; i++)
    {
        int user1 = friendships[i][0] - 1;
        int user2 = friendships[i][1] - 1;
        bool canCommunicate = false;

        for (int j = 0; j < userLanguagesColSize[user1] && !canCommunicate; j++)
        {
            for (int k = 0; k < userLanguagesColSize[user2]; k++)
            {
                if (userLanguages[user1][j] == userLanguages[user2][k])
                {
                    canCommunicate = true;
                    break;
                }
            }
        }

        if (!canCommunicate)
        {
            usersToTeach[user1] = true;
            usersToTeach[user2] = true;
        }
    }

    int minUsersToTeach = userLanguagesSize + 1;

    for (int language = 1; language <= totalLanguages; language++)
    {
        int count = 0;

        for (int user = 0; user < userLanguagesSize; user++)
        {
            if (!usersToTeach[user])
                continue;

            bool knowsLanguage = false;
            for (int j = 0; j < userLanguagesColSize[user]; j++)
            {
                if (userLanguages[user][j] == language)
                {
                    knowsLanguage = true;
                    break;
                }
            }
            if (!knowsLanguage)
                count++;
        }

        if (count < minUsersToTeach)
        {
            minUsersToTeach = count;
        }
    }

    free(usersToTeach);
    return minUsersToTeach;
}
