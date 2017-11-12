#include "i108n.h"
#include <QDebug>
#include <QFile>


/**
 * @brief 国际化构造器(私有隐藏）
 *
 * @param parent
 */
I108n::I108n(QObject *parent)
    : QTranslator(parent),
      m_lang("")
{
    setLang("zh");
}

/**
 * @brief 国际化单例
 *
 * @return I108n 单例指针
 */
I108n *I108n::instance()
{
    static I108n *instance = 0;

    if (!instance)
    {
        instance = new I108n;
    }
    return instance;
}

/**
 * @brief 获取语言
 *
 * @return QString (简称zh,en)
 */
QString I108n::lang()
{
    return m_lang;
}

/**
 * @brief 设置语言
 *
 * @param lang (简称zh,en)
 */
void I108n::setLang(const QString &lang)
{
    if(lang != m_lang) {
        m_lang = lang;
        QTranslator::load(QString(I108n_PATH).arg(lang));
        emit languageChanged();
        qDebug() << "The language is " << lang
                 << "; The File Exist: " << QFile(QString(I108n_PATH).arg(lang)).exists();
    }
}
