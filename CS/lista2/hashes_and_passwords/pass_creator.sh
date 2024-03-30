#!/bin/bash

#Generates files containing hashed strings of digits and small letters

# Define the range of lengths
for length in {4..15}; do
    # Generate a random string of the specified length containing digits and small letters
    random_string=$(head /dev/urandom | tr -dc 'a-z0-9' | head -c ${length}; echo '')

    # Calculate the SHA-256 hash of the random string
    md5_hash=$(echo -n "${random_string}" | md5sum | awk '{print $1}')
    sha3_hash=$(echo -n "${random_string}" | sha3sum | awk '{print $1}')
    sha2_hash=$(echo -n "${random_string}" | openssl sha256 | awk '{print $2}')


    # Write the hash to a file    
    echo "${md5_hash}" > "${random_string}_md5sum.txt"
    echo "${sha3_hash}" > "${random_string}_sha3sum.txt"
    echo "${sha2_hash}" > "${random_string}_sha256.txt"

done

