#include "gtkmm/enums.h"
#include <gtkmm.h>

class OrganizerWindow : public Gtk::Window {
public:
  OrganizerWindow() {
    set_title("Media Organizer");
    maximize();

    m_button.set_label("Choose Ingestion Folder");
    m_button.set_margin_top(12);
    m_button.set_margin_bottom(12);
    m_button.set_margin_start(12);
    m_button.set_margin_end(12);
    m_button.set_valign(Gtk::Align::CENTER);
    m_button.set_halign(Gtk::Align::CENTER);
    m_button.set_hexpand(true);
    m_button.set_vexpand(true);
    m_button.signal_clicked().connect(
        sigc::mem_fun(*this, &OrganizerWindow::on_button_clicked));

    m_box.set_margin_top(12);
    m_box.set_hexpand(true);
    m_box.set_vexpand(true);
    m_box.append(m_label);
    m_box.append(m_button);
    set_child(m_box);
  }

protected:
  void on_button_clicked() { m_label.set_text("hello, gtkmm world!"); }

  Gtk::Box m_box{Gtk::Orientation::VERTICAL};
  Gtk::Label m_label{"Welcome to GTKmm"};
  Gtk::Button m_button;
};

int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create("org.example.myapp");

  app->make_window_and_run<OrganizerWindow>(argc, argv);
}
