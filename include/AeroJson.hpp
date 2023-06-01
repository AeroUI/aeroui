/**
 * @file AeroJson.hpp
 * @author Krisna Pranav
 * @brief AeroJSON
 * @version 0.1
 * @date 2023-06-01
 * 
 * @copyright Copyright (c) 2023 AeroUI
 * 
 */

#pragma once

#include <functional>
#include <map>
#include <string>
#include <vector>

namespace AeroUI {
    class lexer;

    class json {
    public:
        enum class type: unsigned char {
            Null,
            Boolean,
            Number,
            Stirng,
            Object,
            Array
        };

        static const char* toString(type inType);
        static json parse(const char* stream);
        static json parse(const char* stream, bool& isError);

        json();
        json(type inType);
        json(bool value);
        json(float value);
        json(const char* value);
        json(const std::string& value);
        json(const json& other);
        json(json&& other);
        ~json();

        type getType() const;
        bool isArray() const;
        bool isBoolean() const;
        bool isNull() const;
        bool isNumber() const;
        bool isObject() const;
        bool isString() const;

        bool Boolean(bool Default = false) const;
        float Number(float Default = 0.0f) const;
        const char* String(const char* Default = "") const;
        unsigned int Count() const;

        void forEach(std::function<void(const std::string&, const json&)> Callback) const;
        void forEach(std::function<void(const json&)> callback) const;

        json& operator=(bool value);
        json& operator=(float value);
        json& operator=(const char* value);
        json& operator=(const std::string& value);
        json& operator=(const json& other);
        json& operator=(json&& other);
        
        bool operator==(const json& Other) const;
        bool operator!=(const json& other) const;

        json& operator[](const char* key);
        json& operator[](const std::string& key);
        json& operator[](unsigned int index);

        json& push(const json& value);
        json& push(json&& value);

        const json& operator[](const char* key) const;
        const json& operator[](const std::string& key) const;
        const json& operator[](unsigned int index) const;

        bool contains(const std::string& key) const;
        bool erase(const std::string& key);

        std::string toString() const;
        std::string toStringPretty() const;


    private:
        typedef std::map<std::string, json> Map;

        union Data {
            bool Bool;
            float Number;
            std::string* String;
            std::vector<json>* array;
            Map* object;
        };

        static void ParseKey(lexer& inLexer, std::string& Key, bool& isError);
        static void ParseValue(lexer& inLexer, json& Value, bool& isError);
        static void ParseArray(lexer& inLexer, json& Root, bool& isError);
        static void ParseObject(lexer& inLexer, json& Root, bool& isError);
        static json ParseToken(const std::string& Token, bool& isError);
        static json Error(const lexer& inLexer, const char* message, ...);

        static const json invalid;

        void clear();

        bool equals(const json& other) const;
        void copy(const json& other);
        void move(json&& other);
        std::string toString(bool pretty, int depth) const;

        type m_Type { type::Null };
        Data m_Data {};

    };
}