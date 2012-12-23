all:
	cd src; $(MAKE) $(MFLAGS)

clean:
	cd src; $(MAKE) clean

format:
	astyle  --style=ansi \
			--indent=spaces=4 \
			--indent-col1-comments \
			--min-conditional-indent=0 \
			--max-instatement-indent=60 \
			--break-blocks \
			--pad-oper \
			--pad-header \
			--delete-empty-lines \
			--break-closing-brackets \
			--convert-tabs \
			--align-pointer=type \
			-r '*.cpp' '*.h'
