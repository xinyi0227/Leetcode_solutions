class FoodRatings {
  constructor(foods, cuisines, ratings) {
    const makeHeap = (cmp) => {
      const a = [];
      const peek = () => (a.length ? a[0] : null);
      const push = (v) => {
        a.push(v);
        let i = a.length - 1;
        while (i > 0) {
          const p = (i - 1) >> 1;
          if (cmp(a[p], a[i])) break;
          [a[p], a[i]] = [a[i], a[p]];
          i = p;
        }
      };
      const pop = () => {
        if (!a.length) return null;
        const top = a[0];
        const last = a.pop();
        if (a.length) {
          a[0] = last;
          let i = 0;
          for (;;) {
            let l = (i << 1) + 1, r = l + 1, m = i;
            if (l < a.length && cmp(a[l], a[m])) m = l;
            if (r < a.length && cmp(a[r], a[m])) m = r;
            if (m === i) break;
            [a[i], a[m]] = [a[m], a[i]];
            i = m;
          }
        }
        return top;
      };
      return { peek, push, pop };
    };

    this.foodToCuisine = new Map();
    this.foodToRating = new Map();
    this.cuisineToFoods = new Map();
    for (let i = 0; i < foods.length; i++) {
      const f = foods[i], c = cuisines[i], r = ratings[i];
      this.foodToCuisine.set(f, c);
      this.foodToRating.set(f, r);
      if (!this.cuisineToFoods.has(c)) {
        this.cuisineToFoods.set(
          c,
          makeHeap((a, b) => (a.rating !== b.rating ? a.rating > b.rating : a.food < b.food))
        );
      }
      this.cuisineToFoods.get(c).push({ rating: r, food: f });
    }
  }
  changeRating(food, newRating) {
    const c = this.foodToCuisine.get(food);
    this.foodToRating.set(food, newRating);
    this.cuisineToFoods.get(c).push({ rating: newRating, food });
  }
  highestRated(cuisine) {
    const h = this.cuisineToFoods.get(cuisine);
    for (;;) {
      const top = h.peek();
      if (!top) return "";
      if (this.foodToRating.get(top.food) === top.rating) return top.food;
      h.pop();
    }
  }
}
