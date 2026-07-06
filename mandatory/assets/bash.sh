#!/bin/bash

# Clean up existing xpm files first
if [ -d "xpm" ]; then
    echo "Cleaning existing xpm files..."
    rm -rf xpm/*
    echo "Cleanup completed!"
fi

mkdir -p xpm

# Function to convert files and maintain directory structure
convert_files() {
    local extension="$1"
    
    # Find all files with the given extension in png directory and subdirectories
    find png -name "*.$extension" -type f | while read -r file; do
        # Get the relative path from png directory
        relative_path="${file#png/}"
        
        # Get directory part and filename
        dir_part=$(dirname "$relative_path")
        filename=$(basename "$relative_path" ".$extension")
        
        # Create output directory structure
        output_dir="xpm/$dir_part"
        mkdir -p "$output_dir"
        
        # Convert file
        output_file="$output_dir/$filename.xpm"
        convert "$file" "$output_file"
        echo "Converted: $file -> $output_file"
    done
}

# Convert .png files
convert_files "png"

# Convert .PNG files
convert_files "PNG"

echo "Conversion completed!"
