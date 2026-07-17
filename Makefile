LABS := \
	00-binary-analysis \
	01-arm-qemu \
	02-libfuzzer \
	03-source-instrumentation

.PHONY: clean help

help:
	@echo "Available targets:"
	@echo "  clean  Remove generated files from every lab"
	@echo "  help   Show this help"

clean:
	@for lab in $(LABS); do \
		$(MAKE) -C $$lab clean || exit; \
	done
