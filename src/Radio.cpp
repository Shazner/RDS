/**
 * @file Radio.cpp
 * @brief Implementations for the Radio Class
 */

#include <fstream>
#include <sstream>
#include <iostream>
#include "Radio.hpp"

namespace RDS {
std::string Radio::get_id() const {
    return radio_id;
}

std::string Radio::get_type() const {
    return radio_type;
}

std::string Radio::get_notes() const {
    return notes;
}

RADIO_STATUS Radio::get_status() const {
    return status;
}

bool Radio::is_active() const {
    return active;
}

void Radio::add_note(std::string note) {
    notes = note + " | " + notes;
}

void Radio::clear_notes() {
    notes.clear();
}

/**
 * @brief uses vim to edit the notes string
 * @details
 * 1) Save the notes to a temp file (.RDS_temp_note)
 * 2) Execute bash script
 * 2a) Open temp file in vim
 * 2b) Returns once file is closed
 * 3) Read contents of temp into notes
 * 4) Delete temp file
 */
void Radio::edit_notes() {
    static const std::string& temp_file_name = ".RDS_temp_note";
    static const std::string& vim_bash_script =
        "#!/bin/bash \n"
        "vim " +
        temp_file_name + "\n";
    static const std::string& remove_temp_file = "rm " + temp_file_name + "\n";
    {
        std::ofstream ofile(temp_file_name);
        ofile << notes << '\n';
    }
    if (system(vim_bash_script.data())) {
        throw std::system_error(std::error_code(), "Failed to Launch Vim");
    }
    {
        std::ifstream ifile(temp_file_name);
        if (ifile.good()) {
            // Idea from
            // https://www.tutorialspoint.com/Read-whole-ASCII-file-into-Cplusplus-std-string
            std::ostringstream string_stream;
            string_stream << ifile.rdbuf();
            notes = string_stream.str();
        }
    }
    // Strip off any extra new lines at the end
    while (notes.back() == '\n' || notes.back() == '\r') {
        notes.erase(notes.end() - 1);
    }
    if (system(remove_temp_file.data())) {
        throw std::system_error(std::error_code(),
                                "Failed to remove temp file");
    }
}

void Radio::checkout() {
    status = RADIO_STATUS::CHECKED_OUT;
}

void Radio::checkin() {
    status = RADIO_STATUS::CHECKED_IN;
}

void Radio::activate() {
    active = true;
}

void Radio::deactivate() {
    active = false;
}

std::ostream& operator<<(std::ostream& out, const RADIO_STATUS status) {
    switch (status) {
        case (RADIO_STATUS::CHECKED_IN):
            out << "Checked in";
            break;
        case (RADIO_STATUS::CHECKED_OUT):
            out << "Checked out";
            break;
    }
    return out;
}

bool Radio::operator==(const Radio second) const {
    if (radio_id != second.radio_id) {
        return false;
    }
    if (radio_type != second.radio_type) {
        return false;
    }
    if (notes != second.notes) {
        return false;
    }
    return true;
}

std::ostream& operator<<(std::ostream& out, const Radio& radio) {
    out << "Radio ID: " << radio.radio_id << std::endl;
    out << "Radio Type: " << radio.radio_type << std::endl;
    out << "Radio Status : " << radio.status << std::endl;
    out << "Notes: " << radio.notes << std::endl;
    return out;
}

}  // namespace RDS
