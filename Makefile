
# Build the example program
$(EXAMPLE): $(EXAMPLE_SRC) $(LIBRARY)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -o $@ $< -L. -lCodeHive

# Install the library (to /usr/local by default)
install: $(LIBRARY) $(HEADERS)
	install -d $(DESTDIR)/usr/local/lib
	install -m 644 $(LIBRARY) $(DESTDIR)/usr/local/lib
	install -d $(DESTDIR)/usr/local/include
	install -m 644 $(HEADERS) $(DESTDIR)/usr/local/include

# Clean build files
clean:
	rm -rf $(BUILDDIR)
	rm -f $(LIBRARY)
	rm -f $(TEST)
	rm -f $(EXAMPLE)

.PHONY: all directories install clean
