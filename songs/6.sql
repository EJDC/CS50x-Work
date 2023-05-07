SELECT * from SONGS
JOIN ARTISTS ON artists.artist_id = songs.artist_id
WHERE artists.name = 'Post Malone';