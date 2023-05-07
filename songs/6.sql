SELECT * from SONGS
JOIN ARTISTS on artist.artist_id = artists.artist_id
WHERE artists.name = 'Post Malone';