class Solution:
    def countMentions(self, numberOfUsers, events):
        def key(ev):
            t = int(ev[1])
            p = 0 if ev[0] == "OFFLINE" else 1
            return (t, p)

        events.sort(key=key)

        n = numberOfUsers
        ans = [0] * n
        offline_until = [0] * n

        i = 0
        m = len(events)
        while i < m:
            t = int(events[i][1])

            while i < m and int(events[i][1]) == t and events[i][0] == "OFFLINE":
                uid = int(events[i][2])
                offline_until[uid] = t + 60
                i += 1

            while i < m and int(events[i][1]) == t and events[i][0] == "MESSAGE":
                for tok in events[i][2].split():
                    if tok == "ALL":
                        for u in range(n):
                            ans[u] += 1
                    elif tok == "HERE":
                        for u in range(n):
                            if offline_until[u] <= t:
                                ans[u] += 1
                    else:
                        if tok.startswith("id"):
                            uid = int(tok[2:])
                            if 0 <= uid < n:
                                ans[uid] += 1
                i += 1

        return ans
