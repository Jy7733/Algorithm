-- 코드를 입력하세요
select
concat('/home/grep/src/',v.board_id,'/',f.file_id,f.file_name,f.file_ext) as file_path
from

(SELECT
board_id
from used_goods_board
order by views desc
limit 1) as v
join used_goods_file as f on v.board_id = f.board_id
order by f.file_id desc