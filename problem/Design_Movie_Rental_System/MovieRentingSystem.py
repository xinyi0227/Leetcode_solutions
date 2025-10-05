import heapq

class MovieRentingSystem:
    def __init__(self, n, entries):
        self.price = {}
        self.avail = {}
        self.rented_heap = [] 
        self.rented = set()
        for shop, movie, price in entries:
            self.price[(shop, movie)] = price
            self.avail.setdefault(movie, [])
            heapq.heappush(self.avail[movie], (price, shop))

    def search(self, movie):
        if movie not in self.avail:
            return []
        h = self.avail[movie]
        ans = []
        tmp = []
        seen_shops = set()

        while h and len(ans) < 5:
            price, shop = heapq.heappop(h)
            if (shop, movie) in self.rented:
                continue
            if shop not in seen_shops:
                ans.append(shop)
                seen_shops.add(shop)
            tmp.append((price, shop)) 
        for item in tmp:
            heapq.heappush(h, item)
        return ans

    def rent(self, shop, movie):
        self.rented.add((shop, movie))
        heapq.heappush(self.rented_heap, (self.price[(shop, movie)], shop, movie))

    def drop(self, shop, movie):
        if (shop, movie) in self.rented:
            self.rented.remove((shop, movie))
        heapq.heappush(self.avail.setdefault(movie, []), (self.price[(shop, movie)], shop))

    def report(self):
        ans = []
        tmp = []
        seen_pairs = set()

        while self.rented_heap and len(ans) < 5:
            price, shop, movie = heapq.heappop(self.rented_heap)
            if (shop, movie) not in self.rented:
                continue 
            if (shop, movie) not in seen_pairs:
                ans.append([shop, movie])
                seen_pairs.add((shop, movie))
            tmp.append((price, shop, movie))
        for item in tmp:
            heapq.heappush(self.rented_heap, item)
        return ans
