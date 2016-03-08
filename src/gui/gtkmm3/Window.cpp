#include "Window.h"

gui::gtkmm3::Window::Window(std::string title):
	mGtkmmButton(Gtk::Stock::OK)
{
	set_title(title);
	set_border_width(16);

	mGtkmmButton.signal_clicked().connect(sigc::mem_fun(*this, &gui::gtkmm3::Window::onGtkmmButtonClicked));

	add(mGtkmmButton);

	mGtkmmButton.show();
}

gui::gtkmm3::Window::~Window()
{
}

void gui::gtkmm3::Window::onGtkmmButtonClicked()
{
	std::cout << "GtkmmButton clicked!" << '\n';
	close();
}
