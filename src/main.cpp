#include <gtkmm.h>

class MyWindow : public Gtk::Window {
public:
  MyWindow() {
    set_title("Basic GTKmm App");
    set_default_size(400, 200);

    m_button.set_label("Click Me!");
    m_button.signal_clicked().connect(
        sigc::mem_fun(*this, &MyWindow::on_button_clicked));

    m_box.set_margin(10);
    m_box.set_spacing(10);
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

  app->make_window_and_run<MyWindow>(argc, argv);
}
