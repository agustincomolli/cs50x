SELECT
   ROUND(AVG(ratings.rating), 2) AS 'Promedio'
FROM
   ratings
   JOIN movies ON ratings.movie_id = movies.id
WHERE
   movies.year = 2012;
