SELECT cat.name, sum(prod.amount) FROM products prod
    INNER JOIN categories cat ON prod.id_categories = cat.id
GROUP BY cat.name;