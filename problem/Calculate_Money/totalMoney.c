int totalMoney(int days)
{
    int nWeeks = days / 7;
    int rDays = days % 7;
    int triSum = (days * (days + 1)) >> 1;
    int triSumWeeks = ((nWeeks - 1) * nWeeks) >> 1;
    return triSum - 42 * triSumWeeks - 6 * nWeeks * rDays;
}