#ifndef TAG_FILTER_H
#define TAG_FILTER_H

#include "filter.h"
#include <QRegExp>
#include <QScopedPointer>


class TagFilter : public Filter
{
	public:
		explicit TagFilter(QString tag, bool invert = false);
		QString match(const QMap<QString, Token> &tokens, bool invert = false) const override;
		QString toString() const override;
		bool compare(const Filter& rhs) const override;

	private:
		QString m_tag;
		QScopedPointer<QRegExp> m_regexp;
};

#endif // TAG_FILTER_H
