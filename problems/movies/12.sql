SELECT
    movies.title
FROM
    movies
    JOIN stars starring_1 ON movies.id = starring_1.movie_id
    JOIN people actor_1 ON starring_1.person_id = actor_1.id
    JOIN stars starring_2 ON movies.id = starring_2.movie_id
    JOIN people actor_2 ON starring_2.person_id = actor_2.id
WHERE
    actor_1.name = 'Bradley Cooper'
    AND actor_2.name = 'Jennifer Lawrence';
