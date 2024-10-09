SELECT ROUND(AVG(songs.energy), 2) AS 'Average Energy'
   FROM songs
   JOIN artists
   ON songs.artist_id = artists.id
   WHERE artists.name = 'Drake';
