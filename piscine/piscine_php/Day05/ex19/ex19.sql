SELECT ABS(DATEDIFF(MIN(date), MAX(date))) AS 'uptime'
FROM member_history;