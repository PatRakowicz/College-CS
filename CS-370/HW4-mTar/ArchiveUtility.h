//
// Created by Rako on 2/01/2024.
//

#ifndef HW4_MTAR_ARCHIVEUTILITY_H
#define HW4_MTAR_ARCHIVEUTILITY_H


#include <string>
#include <vector>
#include "FileMetadata.h"

class ArchiveUtility {
public:
	void archiveFiles(const std::vector<std::string>& filenames, const std::string& archiveName);
	void extractFiles(const std::string& archiveName);
};


#endif //HW4_MTAR_ARCHIVEUTILITY_H
