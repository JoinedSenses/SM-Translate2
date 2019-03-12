/**
 * Escapes a string from a char with a given escaper char
 *
 * @param input            The string to escape
 * @param escape        Char to escape
 * @param escaper        Char to escape with
 * @param output        Output string to store escaped string
 * @param maxlen        Size of the output string
 *
 * @return                 Number of escaped chars
 */
stock int EscapeString(char[] input, int escape, int escaper, char[] output, int maxlen) {
    // Number of chars we escaped
    int escaped = 0;

    // Format output buffer to ""
    Format(output, maxlen, "");


    // For each char in the input string
    for (int offset = 0; offset < strlen(input); offset++) {
        // Get char at the current position
        int ch = input[offset];

        // Found the escape or escaper char
        if (ch == escape || ch == escaper) {
            // Escape the escape char with the escaper^^
            Format(output, maxlen, "%s%c%c", output, escaper, ch);

            // Increase numbers of chars we escaped
            escaped++;
        }
        else {
            // Add other char to output buffer
            Format(output, maxlen, "%s%c", output, ch);
        }
    }

    // Return escaped chars
    return escaped;
}

/**
 * Escapes string's ' or " chars with MySQL rules. Escape char is the \ char
 *
 * @param input            The string to escape
 * @param output        Output string to store escaped string
 * @param maxlen        Size of the output string
 * @param escape         True to escape ' char, false to escape " char
 *
 * @return                 Number of escaped chars
 */
stock int EscapeStringMySQL(char[] input, char[] output, int maxlen, bool escape = true) {
    // Number of chars we escaped
    int escaped = 0;


    // Escape the ' char
    if (escape) {
        escaped = EscapeString(input, '\'', '\\', output, maxlen);
    }

    // Escape the " char
    else {
        escaped = EscapeString(input, '"', '\\', output, maxlen);
    }


    // Return escaped chars
    return escaped;
}


/**
 * Escapes string's ' or " chars with SQLite rules. Escape char is the ' or " char
 *
 * @param input            The string to escape
 * @param output        Output string to store escaped string
 * @param maxlen        Size of the output string
 * @param escape         True to escape ' char, false to escape " char
 *
 * @return                 Number of escaped chars
 */
stock int EscapeStringSQLite(char[] input, char[] output, int maxlen, bool escape = true) {
    // Number of chars we escaped
    int escaped = 0;


    // Escape the ' char
    if (escape) {
        escaped = EscapeString(input, '\'', '\'', output, maxlen);
    }

    // Escape the " char
    else {
        escaped = EscapeString(input, '"', '"', output, maxlen);
    }


    // Return escaped chars
    return escaped;
} 