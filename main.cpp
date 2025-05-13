#include <iostream>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>

using namespace ftxui;

class MainComponent : public ComponentBase {
 public:

  MainComponent() {
    m_message = "No Title";
    m_screen = nullptr;
  }

  MainComponent(ScreenInteractive* screen,const char message[]) {
    m_screen = screen;
    m_message = message;
  }

  void Refresh() {
    m_screen->PostEvent(Event::Custom);
  }

  Element OnRender() override {
    return vbox({
      text(m_message) | center,
      separator(),
      text("Press 'Q' or 'q' to quit.") | center,
    });
  }

  bool OnEvent(Event event) override {
    if (event == Event::Character('q') || event == Event::Character('Q')) {
      m_screen->Exit();
      return true;
    }
    return ComponentBase::OnEvent(event);
  }

  void SetScreen(ScreenInteractive* screen) {
     m_screen = screen;
  }

 private:
  std::string m_message;
  ScreenInteractive* m_screen;
};

int main() {
  auto screen = ScreenInteractive::TerminalOutput();
  auto main_component = std::make_shared<MainComponent>(&screen,"Main Message");
  main_component->Refresh();
  screen.Loop(main_component);
}
