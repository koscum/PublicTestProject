#include "Gtkmm3Project.h"

gui::gtkmm3::Gtkmm3Project::Gtkmm3Project():
	TestProject("GUI/gtk--3")
{
}

gui::gtkmm3::Gtkmm3Project::~Gtkmm3Project()
{
}

int gui::gtkmm3::Gtkmm3Project::main(int argc, char** argv)
{
	Glib::RefPtr<Gtk::Application> application = Gtk::Application::create(argc, argv);

	gui::gtkmm3::Window window(mTitle);

	int asd = application->run(window);
	window.hide();
	return asd;
}
