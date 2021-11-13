/**
 * @file Radio.hpp
 * @brief Radio abstraction
 */
#ifndef RADIO_HPP
#define RADIO_HPP

#include <string>
#include <cstdint>

namespace RDS {
enum class RADIO_STATUS : uint8_t { CHECKED_IN, CHECKED_OUT };
class Radio {
   private:
    std::string radio_id;
    std::string radio_type;
    std::string notes;
    RADIO_STATUS status;
    bool active;

   public:
    Radio(std::string radio_id, std::string radio_type)
        : radio_id(radio_id), radio_type(radio_type) {
        active = true;
    }
    std::string get_id() const;
    std::string get_type() const;
    std::string get_notes() const;
    RADIO_STATUS get_status() const;
    bool is_active() const;
    void add_note(std::string note);
    void clear_notes();
    void edit_notes();
    void checkout();
    void checkin();
    void activate();
    void deactivate();
    friend std::ostream& operator<<(std::ostream& out, const Radio& radio);
};
}  // namespace RDS

#endif  // RADIO_HPP
