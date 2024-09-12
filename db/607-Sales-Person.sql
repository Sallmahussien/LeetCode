# Write your MySQL query statement below
-- SUB QUERY SOLUTION
-- SELECT `name` FROM `SalesPerson` WHERE (
--     `sales_id` NOT IN (
--         SELECT `sales_id` FROM `Orders` WHERE (
--             `com_id` IN (select com_id from `Company` where name = 'RED')
--         )
--     )
-- );

-- JOIN SOLUTION
SELECT `name` FROM `SalesPerson` WHERE
    `sales_id` NOT IN (
        SELECT `sales_id` FROM `Company`
        JOIN `Orders` ON `Company`.`com_id` = `Orders`.`com_id`
        WHERE `name` =  'RED'
    )
;

