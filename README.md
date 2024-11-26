# OpenFIGI Bulk Mapping Tool

A lightweight tool for mapping equity identifiers to FIGI codes in bulk using the [OpenFIGI API](https://www.openfigi.com/api). You can use your own OpenFIGI API key by replacing the default one at the bottom of the application window.

## Table of Contents

- [Features](#features)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage](#usage)
  - [Input File Format](#input-file-format)
  - [Running the Tool](#running-the-tool)
  - [Output Formats](#output-formats)
- [License](#license)
- [Acknowledgements](#acknowledgements)

## Features

- **Bulk Mapping**: Map large lists of equity identifiers to FIGI codes efficiently.
- **Flexible Input**: Supports various base identifiers and optional context values.
- **Multiple Output Formats**: Get results in Raw JSON, Raw Text, or Parsed CSV.
- **Customizable API Key**: Easily replace the default API key with your own for higher rate limits.

## Prerequisites

- **Operating System**: Windows 7 or higher.
- **Dependencies**: Ensure that you have the required libraries and dependencies installed if you're compiling from source.

## Installation

1. **Download the Latest Release**: Get the executable from the [releases page](https://github.com/mdgr122/OpenFIGI/releases).

2. **Optional - Compile from Source**:
   - Clone the repository:
     ```bash
     git clone https://github.com/mdgr122/OpenFIGI.git
     ```
   - Open the solution file in Visual Studio.
   - Build the project to generate the executable.

3. **Obtain an OpenFIGI API Key** *(Optional but Recommended)*:
   - Sign up for an API key at the [OpenFIGI API portal](https://www.openfigi.com/api).

## Usage

### Input File Format

The input file should be a plain text file (`*.txt`) containing a list of identifiers. Each line includes a base identifier and an optional context value, separated by a space.

#### Base Identifiers

- **TICKER**
- **ISIN**
- **CUSIP**
- **SEDOL**
- **COMPOSITE_FIGI**

#### Optional Context Values

- **Currency**
- **MIC Code**
- **Bloomberg Exchange Code**

> **Note**: When searching for an **index**, you must append `" Index"` to the index ticker. This is how the OpenFIGI API labels equity indices.

#### Sample Input File (`input.txt`)
AAPL XNGS 
AAPL UW 
CAR.UN 
SPX Index 
TSLA
US0378331005
US88160R1014 UN


### Running the Tool

1. **Launch the Application**: Double-click the executable to start the tool.

2. **Select Input File**:
   - Click the **File** button to browse and select your input text file.

3. **Specify Output Path**:
   - Click the **Save** button to choose the destination and name for your output file.
   - Use the **:** button to specify the save path.

4. **Enter API Key** *(Optional)*:
   - Replace the default API key at the bottom of the application window with your own if you have one.

5. **Execute the Mapping**:
   - Click the **REQUEST** button to start the mapping process.
   - The status messages will update to reflect the progress.

6. **Save the Results**:
   - Once processing is complete, click the **Save** button to output the results in your chosen format.

### Output Formats

- **Raw JSON**: The unprocessed JSON response directly from the OpenFIGI API.
- **Raw Text**: A plain text version of the response.
- **Parsed CSV**: A CSV file with the parsed and structured results for easy analysis in spreadsheet applications.

## License

This project is licensed under the [MIT License](LICENSE).

## Acknowledgements

- **OpenFIGI API**: For providing the essential mapping service.
- **Contributors**: Thanks to everyone who has contributed to this project.

---

*For any issues or feature requests, please open an issue on the [GitHub repository](https://github.com/mdgr122/OpenFIGI/issues).*
