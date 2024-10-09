SELECT
    others.name
FROM
    movies
    JOIN stars starring_kevin ON movies.id = starring_kevin.movie_id
    JOIN people kevin_bacon ON starring_kevin.person_id = kevin_bacon.id
    JOIN stars with_kevin ON movies.id = with_kevin.movie_id
    JOIN people others ON with_kevin.person_id = others.id
WHERE
    kevin_bacon.name = 'Kevin Bacon'
    AND kevin_bacon.birth = 1958
    AND others.name != 'Kevin Bacon';
