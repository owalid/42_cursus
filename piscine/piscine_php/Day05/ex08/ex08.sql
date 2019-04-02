SELECT last_name, first_name, SUBSTRING(birthdate, 1, 10) AS birthdate
FROM user_card
WHERE YEAR(birthdate) LIKE 1989 
ORDER BY last_name ASC