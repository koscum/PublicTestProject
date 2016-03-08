#ifndef GTKMM3PROJECT
#define GTKMM3PROJECT

#include "../../TestProject.h" // Base class: TestProject
#include "Window.h"

#include <gtk/gtk.h>
#include <gtkmm.h>

namespace gui
{
	namespace gtkmm3
	{

		class Gtkmm3Project : public ::TestProject
		{
		public:
			Gtkmm3Project();
			virtual ~Gtkmm3Project();

			virtual int main(int argc, char** argv);
		};

	}
}

#endif // GTKMM3PROJECT
