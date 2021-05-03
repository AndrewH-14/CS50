SELECT COUNT(id) FROM
movies JOIN ratings ON id = movie_id
WHERE rating = 10;