#ifndef I108N_H
#define I108N_H

#include <QTranslator>
#define I108n_PATH ":/I108n/lang_%1.qm"
/**
 * @brief 国际化（注意宏I108n_PATH指定语言路径）
 *
 */

class I108n: public QTranslator
{

    Q_OBJECT
       Q_PROPERTY(QString lang READ lang WRITE setLang NOTIFY languageChanged)
   private:

       /**
        * @brief 国际化构造器(私有隐藏）
        *
        * @param parent
        */
       explicit I108n(QObject *parent = 0);
       QString m_lang;

   signals:
       void languageChanged();

   public:
       /**
        * @brief 国际化单例
        *
        * @return I108n 单例指针
        */
       static I108n *instance();

       /**
        * @brief 获取语言
        *
        * @return QString (简称zh,en)
        */
       QString lang();

       /**
        * @brief 设置语言
        *
        * @param lang (简称zh,en)
        */
       void setLang(const QString &lang);
};

#endif // I108N_H
