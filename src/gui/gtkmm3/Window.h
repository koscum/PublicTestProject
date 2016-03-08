#ifndef GUI_GTKMM3_WINDOW
#define GUI_GTKMM3_WINDOW

#include <gtkmm/button.h>
#include <gtkmm/stock.h>
#include <gtkmm/applicationwindow.h>
#include <iostream>

namespace gui
{
	namespace gtkmm3
	{

		class Window: public Gtk::ApplicationWindow
		{
		public:
			Window(std::string title);
			virtual ~Window();

		private:
			void onGtkmmButtonClicked();

			Gtk::Button mGtkmmButton;
		};

	}
}

#endif // GUI_GTKMM3_WINDOW
