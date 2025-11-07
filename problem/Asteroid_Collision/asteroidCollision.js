/**
 * @param {number[]} asteroids
 * @return {number[]}
 */
var asteroidCollision = function(asteroids) {
    const stack = [];
    
    for (const asteroid of asteroids) {
        let alive = true;
        
        while (stack.length > 0 && asteroid < 0 && stack[stack.length - 1] > 0) {
            if (stack[stack.length - 1] < -asteroid) {
                stack.pop();
                continue;
            } else if (stack[stack.length - 1] === -asteroid) {
                stack.pop();
            }
            alive = false;
            break;
        }
        
        if (alive) {
            stack.push(asteroid);
        }
    }
    
    return stack;
};