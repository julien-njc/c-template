#include <cargs.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static struct cag_option options[] = {
    {.identifier = 'h',
     .access_letters = "h",
     .access_name = "help",
     .value_name = NULL,
     .description = "Display the command line help"}};

void showHelp()
{
	printf("Usage: cpptemplate_app [OPTIONS] ...\n");
	printf("Base template to build a C++ library or app with integrated unit tests and documentation.\n");
	cag_option_print(options, CAG_ARRAY_SIZE(options), stdout);
}

typedef struct program_config
{
	bool showHelp;
} program_config;

void program_config_init(program_config* config)
{
	if (config)
	{
		config->showHelp = false;
	}
	else
	{
		perror("program config is not initialized correctly");
	}
}

int main(int argc, char** argv)
{
	cag_option_context context;
	cag_option_prepare(&context, options, CAG_ARRAY_SIZE(options), argc, argv);

	program_config config;
	program_config_init(&config);

	while (cag_option_fetch(&context))
	{
		const char identifier = cag_option_get(&context);
		switch (identifier)
		{
		case 'h':
			config.showHelp = true;
			break;

		default:
			break;
		}
	}

	if (config.showHelp)
	{
		showHelp();
		return (EXIT_SUCCESS);
	}

	return (EXIT_SUCCESS);
}
