

// parser.hpp
#ifndef PARSER_H
#define PARSER_H

#include <string>

class Parser {
private:
    bool avl_mode_;
    bool trace_mode_;
    std::string init_mode_; // manual, random, file
    int size_;
    std::string filename_;
public:
    Parser(int argc, char* argv[])
        : avl_mode_(false), trace_mode_(false), init_mode_("manual"), size_(0) {
        for (int i = 1; i < argc; ++i) {
            std::string arg(argv[i]);
            if (arg == "-ab" && i + 1 < argc) {
                std::string type(argv[++i]);
                avl_mode_ = (type == "avl");
            }
            else if (arg == "-trace" && i + 1 < argc) {
                std::string trace(argv[++i]);
                trace_mode_ = (trace == "y");
            }
            else if (arg == "-init" && i + 1 < argc) {
                init_mode_ = argv[++i];
                if (init_mode_ == "random" && i + 1 < argc) {
                    size_ = std::stoi(argv[++i]);
                }
                else if (init_mode_ == "file" && i + 2 < argc) {
                    size_ = std::stoi(argv[++i]);
                    filename_ = argv[++i];
                }
            }
        }
    }

    bool isAVL() const { return avl_mode_; }
    bool isTrace() const { return trace_mode_; }
    std::string getInitMode() const { return init_mode_; }
    int getSize() const { return size_; }
    std::string getFilename() const { return filename_; }
};

#endif // PARSER_HPP
