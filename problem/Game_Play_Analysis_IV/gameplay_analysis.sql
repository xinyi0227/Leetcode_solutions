 SELECT  ROUND( 
    COUNT(DISTINCT TAB.player_id)/ (SELECT COUNT(DISTINCT player_id)  FROM Activity),2) fraction
 FROM
    (SELECT *, row_number() OVER(PARTITION BY player_id  ORDER BY event_date) rn 
    FROM Activity) TAB
 JOIN Activity 
 ON Activity.player_id = TAB.player_id AND DATEDIFF(Activity.event_date, TAB.event_date) = 1
 WHERE rn = 1