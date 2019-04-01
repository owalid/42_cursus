SELECT COUNT(*) AS 'films' 
FROM film 
JOIN member_history 
WHERE (member_history.date
        BETWEEN '2006-10-30' AND '2007-07-27' 
        OR (MONTH(member_history.date) = 12 
        AND DAY(member_history.date) = 24)) 
AND member_history.id_film = film.id_film;
/*1*/