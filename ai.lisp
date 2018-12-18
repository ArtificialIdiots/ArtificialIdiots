
(format T "~A~%" "你好我的朋友")
(setq input NIL)
(loop
	(print '>>>)
	(setq input (read))
	(cond
		((search "再见" (write-to-string input))
			(return)
		)
		((search "你好" (write-to-string input))
			(format T "~A~%" "你好!")			
		)
		((search "大家好" (write-to-string input))
			(format T "~A~%" "大家好!")			
		)
		(input
			(let ((reply (write-to-string input)))
				(if (search "?" reply)	; Replace normal ?
					(replace reply "!" :start1 (search "?" reply))
				)
				(if (search "？" reply)	; Replace width ?
					(replace reply "!" :start1 (search "？" reply))
				)
				(if (search "吗" reply)	; Replace 吗
					(replace reply " " :start1 (search "吗" reply))
				)
				(if (search "你" reply)	; Replace 你
					(replace reply "我" :start1 (search "你" reply))
				)
				(format T "~A~%" reply)
			) 
		)
		(T)	; Do nothing
	)
)

(format T "~A~%" "再见我的朋友！")
