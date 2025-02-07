#include <iostream>
#include <string>
#include <Windows.h>


class Text {
public:
	virtual void render(const std::string& data) const {
		std::cout << data;
	}
};

class DecoratedText : public Text {
public:
	explicit DecoratedText(std::shared_ptr<Text> text) : text_(text) {}
	std::shared_ptr<Text> text_;
};

class ItalicText : public DecoratedText {
public:
	explicit ItalicText(std::shared_ptr<Text> text) : DecoratedText(text) {}
	void render(const std::string& data)  const {
		std::cout << "<i>";
		text_->render(data);
		std::cout << "</i>";
	}
};

class BoldText : public DecoratedText {
public:
	explicit BoldText(std::shared_ptr<Text> text) : DecoratedText(text) {}
	void render(const std::string& data) const {
		std::cout << "<b>";
		text_->render(data);
		std::cout << "</b>";
	}
};

class Paragraph : public DecoratedText {
public:
	explicit Paragraph(std::shared_ptr<Text> text) : DecoratedText(text) {}
	void render(const std::string& data) const {
		std::cout << "<p>";
		text_->render(data);
		std::cout << "</p>";
	}
};

class Reversed : public DecoratedText {
public:
	explicit Reversed(std::shared_ptr<Text> text) : DecoratedText(text) {}
	void render(const std::string& data) const {
		std::string _data_{ data };
		std::reverse(_data_.begin(), _data_.end());
		text_->render(_data_);
	}
};

class Link : public DecoratedText {
public:
	explicit Link(std::shared_ptr<Text> text) : DecoratedText(text) {}
	void render(const std::string& data, const std::string& data1) const {
		std::cout << "<a href=";
		text_->render(data);
		std::cout << ">";

		text_->render(data1);
		std::cout << "</a>";
	}
};



int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	auto text = std::make_shared<Text>();
	auto bold_text = std::make_shared<BoldText>(text);
	auto text_block = std::make_shared<ItalicText>(bold_text);

	text_block->render("Hello world");
	std::cout << std::endl;

	auto text_block1 = std::make_shared<Paragraph>(text);
	text_block1->render("Hello world");
	std::cout << std::endl;

	auto text_block2 = std::make_shared<Reversed>(text);
	text_block2->render("Hello world");
	std::cout << std::endl;

	auto text_block3 = std::make_shared<Link>(text);
	text_block3->render("netology.ru", "Hello world");
	std::cout << std::endl;

	return 0;
}