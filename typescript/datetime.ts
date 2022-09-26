import date_fns_mgr = require('date-fns')

const G_STR_TIME_FORMAT = 'yyyy-MM-dd HH:mm:ss.SSS'

function print_format() {
    let format_time_str = date_fns_mgr.format(new Date(), G_STR_TIME_FORMAT)
    let parse_date = date_fns_mgr.parse(format_time_str, G_STR_TIME_FORMAT, new Date())

    console.log(format_time_str)
    console.log(parse_date)
}

function print_diff() {
    let cur_date = new Date()
    let prev_year = date_fns_mgr.addYears(cur_date, 1)
    let next_year = date_fns_mgr.subYears(cur_date, 1)
    let prev_month = date_fns_mgr.addMonths(cur_date, 1)
    let next_month = date_fns_mgr.subMonths(cur_date, 1)
    let prev_date = date_fns_mgr.addDays(cur_date, 1)
    let next_date = date_fns_mgr.subDays(cur_date, 1)

    let diff_years = date_fns_mgr.differenceInYears(cur_date, next_year)
    let diff_months = date_fns_mgr.differenceInMonths(cur_date, next_year)
    let diff_days = date_fns_mgr.differenceInDays(cur_date, next_year)
    let is_equal = date_fns_mgr.compareAsc(cur_date, next_year)

    console.log(date_fns_mgr.format(cur_date, G_STR_TIME_FORMAT))

    console.log(date_fns_mgr.format(prev_year, G_STR_TIME_FORMAT))
    console.log(date_fns_mgr.format(next_year, G_STR_TIME_FORMAT))
    console.log(date_fns_mgr.format(prev_month, G_STR_TIME_FORMAT))
    console.log(date_fns_mgr.format(next_month, G_STR_TIME_FORMAT))
    console.log(date_fns_mgr.format(prev_date, G_STR_TIME_FORMAT))
    console.log(date_fns_mgr.format(next_date, G_STR_TIME_FORMAT))

    console.log(diff_years, diff_months, diff_days, is_equal)
}


print_format()
print_diff()
