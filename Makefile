export project_dir := $(shell pwd)
export src_dir := $(project_dir)/src
export build_dir := $(project_dir)/build

all refrigerator:
	-mkdir -p $(build_dir)
	cd $(src_dir) && $(MAKE) $@

clean:
	-rm $(build_dir)/*

.PHONY: all clean
