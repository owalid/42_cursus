SELECT UPPER(last_name) AS "NAME", first_name, subscription.price AS "PRICE"
FROM user_card
JOIN member, subscription
WHERE user_card.id_user = member.id_user_card
AND member.id_sub = subscription.id_sub
AND subscription.price > 42
ORDER BY last_name ASC, first_name ASC