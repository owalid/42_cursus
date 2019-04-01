SELECT genre.id_genre AS 'id_genre', genre.name AS 'name_genre', distrib.id_distrib AS 'id_distrib', distrib.name AS 'id_distrib', film.title AS 'title_film'
FROM film 
LEFT JOIN genre ON genre.id_genre = film.id_genre 
LEFT JOIN distrib ON distrib.id_distrib = film.id_distrib 
WHERE film.id_genre BETWEEN 4 AND 8