#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WText>

class LocalDocApplication : public Wt::WApplication {
    public:
        LocalDocApplication(const Wt::WEnvironment& env);
    private:
        Wt::WLineEdit *nameEdit_;
        Wt::WText *greeting_;
        void greet();
};

LocalDocApplication::LocalDocApplication(const Wt::WEnvironment& env) : Wt::WApplication(env) {
    setTitle("LocalDoc");
    root()->addWidget(new Wt::WText("Document Title: "));
    nameEdit_ = new Wt::WLineEdit(root());
    Wt::WPushButton *button = new Wt::WPushButton("Hello",root());
    root()->addWidget(new Wt::WBreak());
    greeting_ = new Wt::WText(root());
    button->clicked().connect(this, &LocalDocApplication::greet);
}

void LocalDocApplication::greet() {
    greeting_->setText("Document " + nameEdit_->text());
}

Wt::WApplication *createApplication(const Wt::WEnvironment& env) {
    return new LocalDocApplication(env);
}

int main(int argc, char **argv) {
    return Wt::WRun(argc, argv, &createApplication);
}
