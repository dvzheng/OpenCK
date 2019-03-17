#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "../../files/filepaths.h"
#include "world/data.h"

#include <QObject>

class ESMReader;
class ESMWriter;

class Document : public QObject
{
    Q_OBJECT

public:
    Document(const QStringList& files, bool isNew);
    ~Document();

    void load(const QString& fileName);
    void save(const QString& savePath);

    void setAuthor(const QString& author);
    void setDescription(const QString& desc);

    bool isNewFile();

private:
    void createBase();

    FilePaths paths;
    QStringList derivedFiles;
    QString savePath;
    bool newFile;

    Data data;
};

#endif // DOCUMENT_H
