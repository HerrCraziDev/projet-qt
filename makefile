dump:
	@echo Args: $(filter-out $@,$(MAKECMDGOALS))

gui:
	@echo "###### Building GUI ######"
	make -C src/gui $(filter-out $@,$(MAKECMDGOALS))
	@echo "##########################"

simu:
	@echo "## Building simulation ##"
	make -C src/simulation $(filter-out $@,$(MAKECMDGOALS))
	@echo "#########################"

%:
	@:
