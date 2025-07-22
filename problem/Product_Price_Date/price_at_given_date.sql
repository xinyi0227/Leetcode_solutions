WITH RecentPrices AS (
    SELECT 
        p1.product_id, 
        p1.new_price,
        ROW_NUMBER() OVER (PARTITION BY p1.product_id ORDER BY p1.change_date DESC) AS rn
    FROM 
        products p1
    WHERE 
        p1.change_date <= '2019-08-16'
),
ProductList AS (
    SELECT DISTINCT 
        product_id 
    FROM 
        products
)

SELECT 
    p.product_id, 
    IFNULL(rp.new_price, 10) AS price
FROM 
    ProductList p
LEFT JOIN 
    RecentPrices rp ON p.product_id = rp.product_id AND rp.rn = 1;