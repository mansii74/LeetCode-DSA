# Write your MySQL query statement below
-- select s.user_id,
--     round(sum(c.action='confirmed')/count(c.action),2) as confirmation_rate
-- from Signups s
-- left join Confirmations c
-- on s.user_id = c.user_id
-- group by s.user_id
SELECT s.user_id,
       round(avg(if(c.action="confirmed",1,0)),2) AS confirmation_rate
FROM Signups s
LEFT JOIN Confirmations c
ON s.user_id = c.user_id
GROUP BY s.user_id;