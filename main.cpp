#include <iostream>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>

using namespace ftxui;

void clear() {
    std::system("clear");
}

Element TitleBar() {
  return text("  🛰  My Cool Terminal UI  ")  // padded for aesthetics
         | color(Color::White)              // text color
         | bgcolor(Color::Blue)             // background color
         | bold                             // optional: make it bold
         | center;
}

class MainComponent : public ComponentBase {
 public:

  MainComponent() {
    m_title = "No Title";
    m_screen = nullptr;
  }

  MainComponent(ScreenInteractive* screen,const char title[]) {
    m_screen = screen;
    m_title = title;
  }

  void Refresh() {
    m_screen->PostEvent(Event::Custom);
  }

  Element OnRender() override {
    int width = m_screen->dimx();
    int height = m_screen->dimy();
    return vbox({
      TitleBar(),
      separator(),
      text(m_title),
      text("Width: " + std::to_string(width)) | center,
      text("Height: " + std::to_string(height)) | center,
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
  std::string m_title;
  ScreenInteractive* m_screen;
};

int main() {
  clear();
  auto screen = ScreenInteractive::TerminalOutput();
  auto main_component = std::make_shared<MainComponent>(&screen,"My Special Component");
  main_component->Refresh();
  screen.Loop(main_component);
  clear();
}
