SELECT film.title AS 'Title', film.summary AS 'Summary'
FROM film
JOIN genre 
WHERE genre.id_genre = film.id_genre
AND genre.name = 'erotic'
ORDER BY film.prod_year DESC