SELECT prod.id, prod.name FROM products AS prod
    INNER JOIN categories AS cat ON (prod.id_categories = cat.id)
WHERE cat.name LIKE 'super%';
