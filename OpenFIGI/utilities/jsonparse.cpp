#include "jsonparse.h"

JsonParse::JsonParse() : m_json_data{}
{
}

JsonParse::~JsonParse()
{
}

void JsonParse::read_json()
{
	std::vector<std::string> vec{};

	std::string json_path{};
	//json_path = "C:/Users/MDaki/source/repos/OpenFIGI/OpenFIGI/tests/Testing_2.json";
	json_path = "C:/Temp1/UnstructuredData.json";

	std::ifstream ifs(json_path);

	m_json_data = nlohmann::json::parse(ifs);


	int t{};
	nlohmann::json json_obj = m_json_data[t];
	nlohmann::json json_data_obj = m_json_data[t]["data"];
	//std::cout << json_data_obj << std::endl;


	size_t main_counter = 0;
	size_t counter = 0;

	std::string header_line{};
	std::string row_line{};
	
	// Header Loop
	// Loops through each object in the array.
	for (nlohmann::json::iterator i = json_obj.begin(); i != json_obj.end(); ++i)
	{
		//vec.push_back(i.key());
		if (i.key() != "data")
		{
			header_line.append(i.key());
			header_line.append(",");
		}


		if (i.key() == "data")
		{
			// Loops through each object in a json object whose value is an array of objects
			for (nlohmann::json::iterator el = (i.value()).begin(); el != (i.value()).end(); ++el)
			{

				while (counter < json_obj["data"][0].size())
				{
					for (nlohmann::json::iterator nel = (el.value()).begin(); nel != (el.value()).end(); ++nel)
					{

						header_line.append(nel.key());
						header_line.append(",");
						counter++;
					}
				}
			}
		}

	}
	std::cout << std::endl << std::endl << "###############################################" << std::endl << std::endl;
	vec.push_back(header_line);


	size_t json_obj_count = 0;
	size_t data_obj_count = 0;
	size_t parent_counter = 0;
	size_t child_counter = 1;
	size_t child_child_counter = 0;
	// 1

	nlohmann::json data = m_json_data;


	for (nlohmann::json::iterator it = data.begin(); it != data.end(); ++it)
	{
		nlohmann::json json_obj = m_json_data[t];
		for (nlohmann::json::iterator i = json_obj.begin(); i != json_obj.end(); ++i)
		{

			// 2
			// Loops through each object in a json object whose value is an array of objects
			for (nlohmann::json::iterator el = (i.value()).begin(); el != (i.value()).end(); ++el)
			{
				child_counter = 1;
				child_child_counter = 0;
				if (!row_line.empty())
				{
					if (row_line.size() > 99)
					{
						vec.push_back(row_line);

					}
				}
				row_line.clear();

				for (nlohmann::json::iterator nel = (el.value()).begin(); nel != (el.value()).end(); ++nel)
				{
					if (i.key() == "data")
					{
						row_line.append(nel.value());
						row_line.append(",");
						child_counter++;
					}
				}
				while (child_child_counter < 4)
				{
					// for each obj in data, 2, loop through for the amount of objs in json_obj (i.e., loop through 4 objects twice)
					for (nlohmann::json::iterator j = json_obj.begin(); j != json_obj.end(); j++)
					{
						if (!(j.value().is_array()))
						{
							if (j.value() == nullptr)
							{
								row_line.append("");
							}
							else
							{
								row_line.append(j.value());
							}
							row_line.append(",");
						}
						child_child_counter++;

					}
				}


			}

			parent_counter++;
		}
		t++;
	}

}
